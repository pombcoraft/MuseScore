#pragma once
#include <gmock/gmock.h>
#include "notation/imasternotation.h"

namespace mu::notation {
class MasterNotationMock : public IMasterNotation
{
public:
    MOCK_METHOD(project::INotationProject*, project, (), (const, override));
    MOCK_METHOD(muse::Ret, setupNewScore, (engraving::MasterScore*, const ScoreCreateOptions&), (override));
    MOCK_METHOD(void, applyOptions, (engraving::MasterScore*, const ScoreCreateOptions&, bool), (override));
    MOCK_METHOD(engraving::MasterScore*, masterScore, (), (const, override));
    MOCK_METHOD(void, setMasterScore, (engraving::MasterScore*, bool), (override));
    MOCK_METHOD(INotationPtr, notation, (), (override));
    MOCK_METHOD(int, mscVersion, (), (const, override));
    MOCK_METHOD(IExcerptNotationPtr, createEmptyExcerpt, (const QString&), (const, override));
    MOCK_METHOD(const ExcerptNotationList&, excerpts, (), (const, override));
    MOCK_METHOD(muse::async::Notification, excerptsChanged, (), (const, override));
    MOCK_METHOD(const ExcerptNotationList&, potentialExcerpts, (), (const, override));
    MOCK_METHOD(void, initExcerpts, (const ExcerptNotationList&), (override));
    MOCK_METHOD(void, setExcerpts, (const ExcerptNotationList&), (override));
    MOCK_METHOD(void, resetExcerpt, (IExcerptNotationPtr), (override));
    MOCK_METHOD(void, sortExcerpts, (ExcerptNotationList&), (override));
    MOCK_METHOD(void, setExcerptIsOpen, (const INotationPtr, bool), (override));
    MOCK_METHOD(INotationPartsPtr, parts, (), (const, override));
    MOCK_METHOD(bool, hasParts, (), (const, override));
    MOCK_METHOD(muse::async::Notification, hasPartsChanged, (), (const, override));
    MOCK_METHOD(INotationPlaybackPtr, playback, (), (const, override));
    MOCK_METHOD(void, initNotationSoloMuteState, (const INotationPtr), (override));
    MOCK_METHOD(INotationAutomationPtr, automation, (), (const, override));
};
}
