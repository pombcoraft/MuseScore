#ifndef NOTATIONSOLOMUTESTATE_H
#define NOTATIONSOLOMUTESTATE_H

#pragma once
#include <gmock/gmock.h>
#include "notation/inotationsolomutestate.h"

namespace mu::notation {
class NotationSoloMuteStateMock : public INotationSoloMuteState
{
public:
    MOCK_METHOD(muse::Ret, read, (const engraving::MscReader&, const muse::io::path_t&), (override));
    MOCK_METHOD(muse::Ret, write, (muse::io::IODevice*), (override));
    MOCK_METHOD(bool, trackSoloMuteStateExists, (const engraving::InstrumentTrackId&), (const, override));
    MOCK_METHOD(const SoloMuteState&, trackSoloMuteState, (const engraving::InstrumentTrackId&), (const, override));
    MOCK_METHOD(void, setTrackSoloMuteState, (const engraving::InstrumentTrackId&, const SoloMuteState&), (override));
    MOCK_METHOD(void, removeTrackSoloMuteState, (const engraving::InstrumentTrackId&), (override));
    MOCK_METHOD((muse::async::Channel<engraving::InstrumentTrackId, SoloMuteState>), trackSoloMuteStateChanged, (), (const, override));
};
}

#endif // NOTATIONSOLOMUTESTATE_H