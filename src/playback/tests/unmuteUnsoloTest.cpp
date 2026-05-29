/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-Studio-CLA-applies
 *
 * MuseScore Studio
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore Limited
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "playback/internal/playbackcontroller.h"
#include "notation/tests/mocks/notationmock.h"
#include "notation/tests/mocks/notationsolomutestatemock.h"
#include "notation/tests/mocks/notationinteractionmock.h"
#include "notation/tests/mocks/notationpartsmock.h"
#include "notation/tests/mocks/masternotationmock.h"
#include "notation/tests/mocks/notationplaybackmock.h"
#include "notationscene/utilities/percussionutilities.cpp"
#include "modularity/ioc.h"

using namespace mu::playback;
using namespace mu::notation;
using namespace mu::engraving;
using ::testing::NiceMock;
using ::testing::ReturnRef;
using ::testing::Return;
using ::testing::_;


static const String UNMUTEUNSOLO_DATA_DIR("unmuteunsolo_data/");


class Playback_UnmuteAndUnsoloTests : public ::testing::Test
{
protected:
    void SetUp() override
    {

        m_notation = std::make_shared<NiceMock<NotationMock>>();
        m_soloMuteState = std::make_shared<NiceMock<NotationSoloMuteStateMock>>();
        m_interaction = std::make_shared<NiceMock<NotationInteractionMock>>();
        m_parts = std::make_shared<NiceMock<NotationPartsMock>>();
        m_masterNotation = std::make_shared<NiceMock<MasterNotationMock>>();
        m_notationPlayback = std::make_shared<NiceMock<NotationPlaybackMock>>();

        ON_CALL(*m_masterNotation, playback())
            .WillByDefault(Return(m_notationPlayback));
        ON_CALL(*m_notation, masterNotation())
            .WillByDefault(Return(m_masterNotation));
        ON_CALL(*m_notation, hasVisibleParts())
            .WillByDefault(Return(true));
        ON_CALL(*m_notation, interaction())
            .WillByDefault(Return(m_interaction));
        ON_CALL(*m_notation, soloMuteState())
            .WillByDefault(Return(m_soloMuteState));
        ON_CALL(*m_notation, parts())
            .WillByDefault(Return(m_parts));
        ON_CALL(*m_masterNotation, playback())
            .WillByDefault(Return(m_notationPlayback));
    }

    std::shared_ptr<NiceMock<NotationMock>> m_notation;
    std::shared_ptr<NiceMock<NotationSoloMuteStateMock>> m_soloMuteState;
    std::shared_ptr<NiceMock<NotationInteractionMock>> m_interaction;
    std::shared_ptr<NiceMock<NotationPartsMock>> m_parts;
    std::shared_ptr<NiceMock<MasterNotationMock>> m_masterNotation;
    std::shared_ptr<NiceMock<NotationPlaybackMock>> m_notationPlayback;
};

/*
class TestPlaybackController : public PlaybackController
{
    public:
        using PlaybackController::PlaybackController;

        void updateSoloMuteStates() override {}
};*/

//---------------------------------------------------------
///     UnsoloChannelsTest
///     Create two tracks
///     Solo them
///     Test if UnsoloAll sucessfully unsoloes both tracks.
///
//---------------------------------------------------------

TEST_F(Playback_UnmuteAndUnsoloTests, UnsoloChannelsTest)
{
    InstrumentTrackId track1 {
        ID(QString("part1")),
        muse::String(u"inst1")
    };

    InstrumentTrackId track2 {
        ID(QString("part2")),
        muse::String(u"inst2")
    };


    InstrumentTrackIdSet tracks { track1, track2 };

    ON_CALL(*m_notationPlayback, existingTrackIdSet())
        .WillByDefault(Return(tracks));

    INotationSoloMuteState::SoloMuteState soloState;
    soloState.solo = true;

    static INotationSoloMuteState::SoloMuteState returnedState = soloState;

    ON_CALL(*m_soloMuteState, trackSoloMuteState(_))
        .WillByDefault(ReturnRef(returnedState));
    
    static InstrumentTrackId metronomeTrackId {
        ID(QString("metronome")),
        muse::String(u"metronome")
    };

    ON_CALL(*m_notationPlayback, metronomeTrackId())
        .WillByDefault(ReturnRef(metronomeTrackId));

    EXPECT_CALL(
        *m_soloMuteState,
        setTrackSoloMuteState(
            track1,
            testing::Field(
                &INotationSoloMuteState::SoloMuteState::solo,
                false)))
        .Times(1);

    EXPECT_CALL(
        *m_soloMuteState,
        setTrackSoloMuteState(
            track2,
            testing::Field(
                &INotationSoloMuteState::SoloMuteState::solo,
                false)))
        .Times(1);

    /*
    PlaybackController controller(muse::modularity::globalCtx());

    controller.setNotation(m_notation);

    controller.unsoloAll();*/

    PlaybackController controller(muse::modularity::globalCtx());
    std::cout << "controller created" << std::endl;
     // Test each mock individually
    std::cout << "calling masterNotation" << std::endl << std::flush;
    auto mn = m_notation->masterNotation();
    std::cout << "masterNotation ok: " << (mn ? "not null" : "null") << std::endl << std::flush;
    
    std::cout << "calling interaction" << std::endl << std::flush;
    auto inter = m_notation->interaction();
    std::cout << "interaction ok: " << (inter ? "not null" : "null") << std::endl << std::flush;
    
    std::cout << "calling parts" << std::endl << std::flush;
    auto parts = m_notation->parts();
    std::cout << "parts ok: " << (parts ? "not null" : "null") << std::endl << std::flush;
    //controller.setNotation(m_notation);
    //controller.setMasterNotation(m_masterNotation);
    //controller.m_notation = m_notation;
    controller.setNotationForTest(m_notation, m_masterNotation);
    //controller.m_masterNotation = m_masterNotation;
    //controller.m_notation = m_notation;    
    controller.addInstrumentTrackForTest(track1, 1);
    controller.addInstrumentTrackForTest(track2, 2);
    //controller.setNotationDirect(m_notation);
    std::cout << "notation set" << std::endl;
    controller.unsoloAll();
    std::cout << "unsoloAll called" << std::endl;

}

//---------------------------------------------------------
///     UnmuteChannelsTest
///     Create two tracks
///     Solo them
///     Test if UnmuteAll sucessfully unmutes both tracks.
///
//---------------------------------------------------------

/*
TEST_F(Playback_UnmuteAndUnsoloTests, UnmuteChannelsTest)
{
    InstrumentTrackId track1 {
        ID(QString("part1")),
        muse::String(u"inst1")
    };

    InstrumentTrackId track2 {
        ID(QString("part2")),
        muse::String(u"inst2")
    };

    INotationSoloMuteState::SoloMuteState muteState;
    soloState.mute = true;

    static INotationSoloMuteState::SoloMuteState returnedState = muteState;

    ON_CALL(*m_soloMuteState, trackSoloMuteState(_))
        .WillByDefault(ReturnRef(returnedState));

    EXPECT_CALL(
        *m_soloMuteState,
        setTrackSoloMuteState(
            track1,
            testing::Field(
                &INotationSoloMuteState::SoloMuteState::mute,
                false)))
        .Times(1);

    EXPECT_CALL(
        *m_soloMuteState,
        setTrackSoloMuteState(
            track2,
            testing::Field(
                &INotationSoloMuteState::SoloMuteState::mute,
                false)))
        .Times(1);

    PlaybackController controller(nullptr);

    controller.setNotation(m_notation);

    controller.unmuteAll();

}*/