#pragma once
#include <gmock/gmock.h>
#include "notation/inotationplayback.h"

namespace mu::notation {
class NotationPlaybackMock : public INotationPlayback
{
public:
    MOCK_METHOD(void, init, (), (override));
    MOCK_METHOD(void, reload, (), (override));
    MOCK_METHOD(void, setSendEventsOnScoreChange, (const engraving::InstrumentTrackId&, bool), (override));
    MOCK_METHOD(void, sendEventsForChangedTracks, (), (override));
    MOCK_METHOD(muse::async::Channel<engraving::InstrumentTrackIdSet>, tracksDataChanged, (), (const, override));
    MOCK_METHOD(const engraving::InstrumentTrackId&, metronomeTrackId, (), (const, override));
    MOCK_METHOD(engraving::InstrumentTrackId, chordSymbolsTrackId, (const muse::ID&), (const, override));
    MOCK_METHOD(bool, isChordSymbolsTrack, (const engraving::InstrumentTrackId&), (const, override));
    MOCK_METHOD(const muse::mpe::PlaybackData&, trackPlaybackData, (const engraving::InstrumentTrackId&), (const, override));
    MOCK_METHOD(void, triggerEventsForItems, (const std::vector<const engraving::EngravingItem*>&, muse::mpe::duration_t, bool), (override));
    MOCK_METHOD(void, triggerMetronome, (muse::midi::tick_t), (override));
    MOCK_METHOD(void, triggerCountIn, (muse::midi::tick_t, muse::secs_t&), (override));
    MOCK_METHOD(void, triggerControllers, (const muse::mpe::ControllerChangeEventList&, notation::staff_idx_t, int), (override));
    MOCK_METHOD(engraving::InstrumentTrackIdSet, existingTrackIdSet, (), (const, override));
    MOCK_METHOD(muse::async::Channel<engraving::InstrumentTrackId>, trackAdded, (), (const, override));
    MOCK_METHOD(muse::async::Channel<engraving::InstrumentTrackId>, trackRemoved, (), (const, override));
    MOCK_METHOD(muse::audio::secs_t, totalPlayTime, (), (const, override));
    MOCK_METHOD(muse::async::Channel<muse::audio::secs_t>, totalPlayTimeChanged, (), (const, override));
    MOCK_METHOD(muse::audio::secs_t, playedTickToSec, (muse::midi::tick_t), (const, override));
    MOCK_METHOD(muse::midi::tick_t, secToPlayedTick, (muse::audio::secs_t), (const, override));
    MOCK_METHOD(muse::midi::tick_t, secToTick, (muse::audio::secs_t), (const, override));
    MOCK_METHOD(muse::RetVal<muse::midi::tick_t>, playPositionTickByRawTick, (muse::midi::tick_t), (const, override));
    MOCK_METHOD(muse::RetVal<muse::midi::tick_t>, playPositionTickByElement, (const engraving::EngravingItem*), (const, override));
    MOCK_METHOD(void, addLoopBoundary, (LoopBoundaryType, muse::midi::tick_t), (override));
    MOCK_METHOD(void, setLoopBoundariesEnabled, (bool), (override));
    MOCK_METHOD(bool, isLoopEnabled, (), (const, override));
    MOCK_METHOD(const LoopBoundaries&, loopBoundaries, (), (const, override));
    MOCK_METHOD(muse::async::Notification, loopBoundariesChanged, (), (const, override));
    MOCK_METHOD(const Tempo&, multipliedTempo, (muse::midi::tick_t), (const, override));
    MOCK_METHOD(double, tempoMultiplier, (), (const, override));
    MOCK_METHOD(void, setTempoMultiplier, (double), (override));
    MOCK_METHOD(void, addSoundFlags, (const std::vector<engraving::StaffText*>&), (override));
    MOCK_METHOD(void, removeSoundFlags, (const engraving::InstrumentTrackIdSet&), (override));
    MOCK_METHOD(bool, hasSoundFlags, (const engraving::InstrumentTrackIdSet&), (override));
    MOCK_METHOD(MeasureBeat, beat, (muse::midi::tick_t), (const, override));
    MOCK_METHOD(muse::midi::tick_t, beatToRawTick, (int, int), (const, override));
};
}
