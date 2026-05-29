#pragma once
#include "async/notifylist.h"
#include <gmock/gmock.h>
#include "notation/inotationparts.h"

namespace mu::notation {
class NotationPartsMock : public INotationParts
{
public:
    MOCK_METHOD(muse::async::NotifyList<const Part*>, partList, (), (const, override));
    MOCK_METHOD(muse::async::NotifyList<const Staff*>, staffList, (const muse::ID&), (const, override));
    MOCK_METHOD(bool, hasParts, (), (const, override));
    MOCK_METHOD(const Part*, part, (const muse::ID&), (const, override));
    MOCK_METHOD(bool, partExists, (const muse::ID&), (const, override));
    MOCK_METHOD(const Staff*, staff, (const muse::ID&), (const, override));
    MOCK_METHOD(bool, staffExists, (const muse::ID&), (const, override));
    MOCK_METHOD(StaffConfig, staffConfig, (const muse::ID&, Fraction), (const, override));
    MOCK_METHOD(ScoreOrder, scoreOrder, (), (const, override));
    MOCK_METHOD(void, setParts, (const PartInstrumentList&, const ScoreOrder&), (override));
    MOCK_METHOD(void, setScoreOrder, (const ScoreOrder&), (override));
    MOCK_METHOD(void, setPartVisible, (const muse::ID&, bool), (override));
    MOCK_METHOD(bool, setVoiceVisible, (const muse::ID&, int, bool), (override));
    MOCK_METHOD(void, setStaffVisible, (const muse::ID&, bool), (override));
    MOCK_METHOD(void, setPartSharpFlat, (const muse::ID&, const SharpFlat&), (override));
    MOCK_METHOD(void, setInstrumentName, (const InstrumentKey&, const QString&), (override));
    MOCK_METHOD(void, setInstrumentAbbreviature, (const InstrumentKey&, const QString&), (override));
    MOCK_METHOD(void, setInstrumentGroupNameOptions, (const std::vector<InstrumentKey>&, bool, const QString&, const QString&), (override));
    MOCK_METHOD(void, setInstrumentNumber, (const InstrumentKey&, int), (override));
    MOCK_METHOD(void, setStaffType, (const muse::ID&, StaffTypeId), (override));
    MOCK_METHOD(void, setStaffConfig, (const muse::ID&, const StaffConfig&, Fraction), (override));
    MOCK_METHOD(void, setSharedPartEnabled, (const muse::ID&, bool), (override));
    MOCK_METHOD(void, removeParts, (const muse::IDList&), (override));
    MOCK_METHOD(void, removeStaves, (const muse::IDList&), (override));
    MOCK_METHOD(void, moveParts, (const muse::IDList&, const muse::ID&, InsertMode), (override));
    MOCK_METHOD(void, moveStaves, (const muse::IDList&, const muse::ID&, InsertMode), (override));
    MOCK_METHOD(bool, appendStaff, (Staff*, const muse::ID&), (override));
    MOCK_METHOD(bool, appendStaffLinkedToMaster, (Staff*, Staff*, const muse::ID&), (override));
    MOCK_METHOD(bool, appendLinkedStaff, (Staff*, const muse::ID&, const muse::ID&), (override));
    MOCK_METHOD(void, insertPart, (Part*, size_t), (override));
    MOCK_METHOD(void, replacePart, (const muse::ID&, Part*), (override));
    MOCK_METHOD(void, replaceInstrument, (const InstrumentKey&, const Instrument&, const StaffType*), (override));
    MOCK_METHOD(void, replaceDrumset, (const InstrumentKey&, const Drumset&, bool), (override));
    MOCK_METHOD(const std::vector<Staff*>&, systemObjectStaves, (), (const, override));
    MOCK_METHOD(muse::async::Notification, systemObjectStavesChanged, (), (const, override));
    MOCK_METHOD(void, addSystemObjects, (const muse::IDList&), (override));
    MOCK_METHOD(void, removeSystemObjects, (const muse::IDList&), (override));
    MOCK_METHOD(void, moveSystemObjects, (const muse::ID&, const muse::ID&), (override));
    MOCK_METHOD(void, moveSystemObjectLayerBelowBottomStaff, (), (override));
    MOCK_METHOD(void, moveSystemObjectLayerAboveBottomStaff, (), (override));
    MOCK_METHOD(void, toggleStaveSharing, (bool), (override));
    MOCK_METHOD(muse::async::Notification, partsChanged, (), (const, override));
    MOCK_METHOD(muse::async::Notification, scoreOrderChanged, (), (const, override));
    MOCK_METHOD(muse::async::Notification, sharedPartsChanged, (), (const, override));
};
}
