#include "stdafx.h"
#include "Util.h"
#include "Telex.h"

using namespace VietType::Telex;

namespace VietType {
namespace UnitTests {

TelexStates FeedWord(TelexEngine& e, const wchar_t* input) {
    e.Reset();
    for (auto c : std::wstring(input)) {
        e.PushChar(c);
    }
    return e.GetState();
}

void TestValidWord(TelexEngine& e, const wchar_t* expected, const wchar_t* input) {
    e.Reset();
    for (auto c : std::wstring(input)) {
        AssertTelexStatesEqual(TelexStates::Valid, e.PushChar(c));
    }
    Assert::AreEqual(expected, e.Peek().c_str());
    AssertTelexStatesEqual(TelexStates::Committed, e.Commit());
    Assert::AreEqual(expected, e.Retrieve().c_str());
}

void TestInvalidWord(TelexEngine& e, const wchar_t* expected, const wchar_t* input) {
    e.Reset();
    for (auto c : std::wstring(input)) {
        e.PushChar(c);
    }
    AssertTelexStatesEqual(TelexStates::CommittedInvalid, e.Commit());
    Assert::AreEqual(expected, e.RetrieveRaw().c_str());
}

void TestPeekWord(TelexEngine& e, const wchar_t* expected, const wchar_t* input) {
    FeedWord(e, input);
    Assert::AreEqual(expected, e.Peek().c_str());
}

} // namespace UnitTests
} // namespace VietType
