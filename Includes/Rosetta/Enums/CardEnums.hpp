// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef ROSETTASTONE_CARD_ENUMS_HPP
#define ROSETTASTONE_CARD_ENUMS_HPP

#include <string>

namespace RosettaStone
{
//! \brief An enumerator for identifying the class of the card.
enum class CardClass
{
#define X(a) a,
#include "CardClass.def"
#undef X
};

const std::string CARD_CLASS_STR[] = {
#define X(a) #a,
#include "CardClass.def"
#undef X
};

//! \brief An enumerator for identifying the set of the card.
enum class CardSet
{
#define X(a) a,
#include "CardSet.def"
#undef X
};

const std::string CARD_SET_STR[] = {
#define X(a) #a,
#include "CardSet.def"
#undef X
};

//! \brief An enumerator for identifying the type of the card.
enum class CardType
{
#define X(a) a,
#include "CardType.def"
#undef X
};

const std::string CARD_TYPE_STR[] = {
#define X(a) #a,
#include "CardType.def"
#undef X
};

//! \brief An enumerator for identifying the faction of the card.
enum class Faction
{
#define X(a) a,
#include "Faction.def"
#undef X
};

const std::string FACTION_STR[] = {
#define X(a) #a,
#include "Faction.def"
#undef X
};

//! \brief An enumerator for identifying the game tag of the card.
enum class GameTag
{
#define X(a) a,
#include "GameTag.def"
#undef X
};

const std::string GAME_TAG_STR[] = {
#define X(a) #a,
#include "GameTag.def"
#undef X
};

//! \brief An enumerator for identifying the play requirement of the card.
enum class PlayReq
{
#define X(a) a,
#include "PlayReq.def"
#undef X
};

const std::string PLAY_REQ_STR[] = {
#define X(a) #a,
#include "PlayReq.def"
#undef X
};

//! \brief An enumerator for identifying the race of the card.
enum class Race
{
#define X(a) a,
#include "Race.def"
#undef X
};

const std::string RACE_STR[] = {
#define X(a) #a,
#include "Race.def"
#undef X
};

//! \brief An enumerator for identifying the rarity of the card.
enum class Rarity
{
#define X(a) a,
#include "Rarity.def"
#undef X
};

const std::string RARITY_STR[] = {
#define X(a) #a,
#include "Rarity.def"
#undef X
};

//! \brief An enumerator for identifying the locale of the card.
enum class Locale
{
    UNKNOWN,
    enUS,
    enGB,
    frFR,
    deDE,
    koKR,
    esES,
    esMX,
    ruRU,
    zhTW,
    zhCN,
    itIT,
    ptBR,
    plPL,
    ptPT,
    jaJP,
    thTH
};

//! \brief An enumerator for identifying the mulligan state.
enum class Mulligan
{
    INVALID,
    INPUT,
    DEALING,
    WAITING,
    DONE
};

//! \brief An enumerator for identifying the choice type of the card.
enum class ChoiceType
{
    INVALID,
    MULLIGAN,
    GENERAL
};

//! \brief An enumerator for identifying the format type of the card.
enum class FormatType
{
    UNKNOWN,
    WILD,
    STANDARD
};

//! \brief An enumerator for identifying the play state.
enum class PlayState
{
    INVALID,
    PLAYING,
    WINNING,
    LOSING,
    WON,
    LOST,
    TIED,
    DISCONNECTED,
    CONCEDED
};

//! \brief An enumerator for indicating the state of the card.
enum class State
{
    INVALID,
    LOADING,
    RUNNING,
    COMPLETE
};

//! \brief An enumerator for indicating the game step.
enum class Step
{
    INVALID,
    BEGIN_FIRST,
    BEGIN_SHUFFLE,
    BEGIN_DRAW,
    BEGIN_MULLIGAN,
    MAIN_BEGIN,
    MAIN_READY,
    MAIN_RESOURCE,
    MAIN_DRAW,
    MAIN_START,
    MAIN_ACTION,
    MAIN_COMBAT,
    MAIN_END,
    MAIN_NEXT,
    FINAL_WRAPUP,
    FINAL_GAMEOVER,
    MAIN_CLEANUP,
    MAIN_START_TRIGGERS
};

template <class T>
T StrToEnum(const std::string_view&);
template <class T>
std::string EnumToStr(T);

#define STR2ENUM(TYPE, ARRAY)                                                \
    template <>                                                              \
    inline TYPE StrToEnum<TYPE>(const std::string_view& str)                 \
    {                                                                        \
        for (std::size_t i = 0; i < (sizeof(ARRAY) / sizeof(ARRAY[0])); ++i) \
        {                                                                    \
            if (ARRAY[i] == str)                                             \
            {                                                                \
                return TYPE(i);                                              \
            }                                                                \
        }                                                                    \
                                                                             \
        return TYPE(0);                                                      \
    }

#define ENUM2STR(TYPE, ARRAY)                  \
    template <>                                \
    inline std::string EnumToStr<TYPE>(TYPE v) \
    {                                          \
        return ARRAY[static_cast<int>(v)];     \
    }

#define ENUM_AND_STR(TYPE, ARRAY) \
    STR2ENUM(TYPE, ARRAY)         \
    ENUM2STR(TYPE, ARRAY)

ENUM_AND_STR(CardClass, CARD_CLASS_STR)
ENUM_AND_STR(CardSet, CARD_SET_STR)
ENUM_AND_STR(CardType, CARD_TYPE_STR)
ENUM_AND_STR(Faction, FACTION_STR)
ENUM_AND_STR(GameTag, GAME_TAG_STR)
ENUM_AND_STR(PlayReq, PLAY_REQ_STR)
ENUM_AND_STR(Race, RACE_STR)
ENUM_AND_STR(Rarity, RARITY_STR)
}  // namespace RosettaStone

#endif  // ROSETTASTONE_CARD_ENUMS_HPP
