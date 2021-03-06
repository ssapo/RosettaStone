// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// RosettaStone is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#ifndef ROSETTASTONE_CHARACTER_HPP
#define ROSETTASTONE_CHARACTER_HPP

#include <Rosetta/Models/Entity.hpp>

namespace RosettaStone
{
class Player;

//!
//! \brief Abstract character class that stores hero and minion data.
//!
//! This class inherits from Entity class. Also, it stores some
//! attributes that only characters have such as attack and health.
//!
class Character : public Entity
{
 public:
    //! Default constructor.
    Character() = default;

    //! Constructs character with given \p _owner and \p _card.
    //! \param _owner An owner of the card.
    //! \param _card A reference to the card.
    Character(Player& _owner, Card& _card);

    //! Default destructor.
    virtual ~Character() = default;

    //! Default copy constructor.
    Character(const Character& c) = default;

    //! Default move constructor.
    Character(Character&& c) = default;

    //! Default copy assignment operator.
    Character& operator=(const Character& c) = default;

    //! Default move assignment operator.
    Character& operator=(Character&& c) = default;

    //! Returns the value of attack.
    //! \return The value of attack.
    virtual int GetAttack() const;

    //! Sets the value of attack.
    //! \param attack The value of attack.
    void SetAttack(int attack);

    //! Returns the value of damage.
    //! \return The value of damage.
    int GetDamage() const;

    //! Sets the value of damage.
    //! \param damage The value of damage.
    void SetDamage(int damage);

    //! Returns the value of health.
    //! \return The value of health.
    int GetHealth() const;

    //! Sets the value of health.
    //! \param health The value of health.
    void SetHealth(int health);

    //! Returns the value of base health.
    //! \return The value of base health.
    int GetBaseHealth() const;

    //! Sets the value of base health.
    //! \param baseHealth The value of base health.
    void SetBaseHealth(int baseHealth);

    //! Returns the value of spell power.
    //! \return The value of spell power.
    int GetSpellPower();

    //! Sets the value of spell power.
    //! \param spellPower The value of spell power.
    void SetSpellPower(int spellPower);

    //! Returns whether attack is possible.
    //! \return Whether attack is possible.
    bool CanAttack();

    //! Returns whether the target is valid in combat.
    //! \param opponent The opponent player.
    //! \param target A pointer to the target.
    //! \return true if the target is valid, and false otherwise.
    bool IsValidCombatTarget(Player& opponent, Character* target) const;

    //! Returns a list of valid target in combat.
    //! \param opponent The opponent player.
    //! \return A list of pointer to valid target.
    static std::vector<Character*> GetValidCombatTargets(Player& opponent);

    //! Takes damage from a certain other entity.
    //! \param source An entity to give damage.
    //! \param damage The value of damage.
    //! \return Final damage taking into account ability.
    int TakeDamage(Entity& source, int damage);

    //! Takes heal up all taken damage.
    //! \param source An entity to give full heal.
    void TakeFullHeal(Entity& source);

    //! Takes heal a specified amount of health.
    //! \param source An entity to give heal.
    //! \param heal The value of heal.
    void TakeHeal(Entity& source, int heal);

    std::size_t numAttacked = 0;
};
}  // namespace RosettaStone

#endif  // ROSETTASTONE_CHARACTER_HPP
