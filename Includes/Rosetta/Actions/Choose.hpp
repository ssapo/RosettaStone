// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// RosettaStone is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#ifndef ROSETTASTONE_CHOOSE_HPP
#define ROSETTASTONE_CHOOSE_HPP

#include <Rosetta/Enums/CardEnums.hpp>
#include <Rosetta/Models/Choice.hpp>
#include <Rosetta/Models/Player.hpp>

namespace RosettaStone::Generic
{
//! Choices cards in mulligan state.
//! \param player The player to create a choice cards.
//! \param choices A container of card to choose.
void ChoiceMulligan(Player& player, const std::vector<std::size_t>& choices);

//! Creates a choice for player.
//! \param player The player to create a choice.
//! \param type A choice type.
//! \param action A choice action.
//! \param choices A container of card to choose.
void CreateChoice(Player& player, ChoiceType type, ChoiceAction action,
                  const std::vector<std::size_t>& choices);
}  // namespace RosettaStone::Generic

#endif  // ROSETTASTONE_DRAW_HPP
