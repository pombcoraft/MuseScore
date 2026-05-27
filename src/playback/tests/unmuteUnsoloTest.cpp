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
#include "playback/tests/mocks/playbackcontrollermock.h"
#include "playback/iplaybackcontroller.h"
#include "playback/internal/playbackcontroller.h"
#include "engraving/tests/utils/scorerw.h"
#include "engraving/dom/masterscore.h"

using namespace mu::playback;
using namespace mu::engraving;
using namespace mu::notation;
using namespace mu; // TODO FIX

static const String UNMUTEUNSOLO_DATA_DIR("unmuteunsolo_data/");

class Playback_UmuteAndUnsoloTests : public ::testing::Test
{
};

// TEST IDEAS, test if master was muted, test if metronome was unmuted (muted by default), test muting 3 channels and unmuting them all


//---------------------------------------------------------
///     UnmuteChannelsTest
///     Put a note
///     Add a Laissez-Vibrer tie to it
///     Put another note below it, making a chord
///     Verifies that the new note doesn't have any notes tied it, as would happen if it had a double notehead.
//---------------------------------------------------------

TEST_F(Playback_UmuteAndUnsoloTests, UnmuteChannelsTest)
{
//FIXME - MAYBE ILLEGAL BECAUSE IT COMES FROM ENGRAVING
    MasterScore* score = ScoreRW::readScore(UNMUTEUNSOLO_DATA_DIR + u"three_channels.mscz");

    //nsei oq e isto
    //muse::ContextInject<IPlaybackController> playbackController = { this };

    //m_playbackController = std::make_shared<NiceMock<playback::PlaybackControllerMock> >();
    std::shared_ptr<playback::PlaybackControllerMock> m_playbackController;

    //qt creator ajuda-me

    //const IPlaybackController::InstrumentTrackIdMap& instrumentTrackIdMap = playbackController()->instrumentTrackIdMap();
    const IPlaybackController::InstrumentTrackIdMap& instrumentTrackIdMap = m_playbackController->instrumentTrackIdMap();

    notation::INotationPtr m_notation;

    for (const auto& pair : instrumentTrackIdMap) {
//        if (pair.first == metronomeTrackId) { // TODO - FIX, IGNORE MASTER
//            continue;
        INotationSoloMuteState::SoloMuteState new_state = m_notation->soloMuteState()->trackSoloMuteState(pair.first);
        if(new_state.solo == false) {
            new_state.solo = true;

            setTrackSoloMuteState(pair.first,new_state);
        }
    }

}
    //existingTrackIdSet()

    //const INotationPlaybackPtr notationPlayback = m_masterNotation->playback();

    //InstrumentTrackIdSet existingTrackIdSet = notationPlayback()->existingTrackIdSet();

    //for (const InstrumentTrackId& instrumentTrackId : existingTrackIdSet) {
        //if (instrumentTrackId == notationPlayback()->metronomeTrackId()) {
          //  continue;
        //}

       // INotationSoloMuteState::SoloMuteState new_state = m_notation->soloMuteState()->trackSoloMuteState(instrumentTrackId);
        //if(new_state.mute == true) {
            //new_state.mute = false;

          //  setTrackSoloMuteState(instrumentTrackId,new_state);
        //}
    //}

    //updateSoloMuteStates();




//    score->doLayout();

//    score->inputState().setTrack(0);
//    score->inputState().setSegment(score->tick2segment(Fraction(0, 1), false, SegmentType::ChordRest));
//    score->inputState().setDuration(DurationType::V_QUARTER);
//    score->inputState().setNoteEntryMode(true);

    // Add the First Note
//    score->cmdAddPitch(45, true, false);

//    Measure* m = score->firstMeasure();
//    Chord* c = m->findChord(Fraction(0, 1), 0);
//    EXPECT_EQ(c->ticks(), Fraction(1, 4));

    // Add a Laissez-Vibrer tie to the First Note
//    score->select(c->upNote());
//    score->cmdToggleLaissezVib();

//    EXPECT_TRUE(c->upNote()->tieFor()->isLaissezVib());
//    score->doLayout();

    // Add a Second Note
//    NoteVal newNoteVal(71);
//    Note* second_note = score->addPitch(newNoteVal, true);

    // Check if there is a double notehead
//    std::vector<Note*> tn = second_note->tiedNotes();
//    EXPECT_TRUE(tn.size() < 2);

//    const String savePath = u"lv_test.mscx";
//    ScoreRW::saveScore(score, savePath);
//}
