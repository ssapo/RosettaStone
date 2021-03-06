// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef ROSETTASTONE_ENTITY_HPP
#define ROSETTASTONE_ENTITY_HPP

#include <Rosetta/Cards/Card.hpp>
#include <Rosetta/Enchants/AuraEffects.hpp>

#include <map>

namespace RosettaStone
{
class Card;
class Game;
class Player;

//!
//! \brief Abstract entity structure that stores card data.
//!
//! This structure is base structure of all data-holding/action-performing/
//! visible or invisible objects in a RosettaStone.
//! An entity is defined as a collection of properties, called GameTags.
//!
class Entity
{
 public:
    //! Default constructor.
    Entity() = default;

    //! Constructs entity with given \p _owner and \p _card.
    //! \param _owner An owner of the card.
    //! \param _card A reference to the card.
    Entity(Player& _owner, Card& _card);

    //! Destructor.
    virtual ~Entity();

    //! Copy constructor.
    Entity(const Entity& ent);

    //! Move constructor.
    Entity(Entity&& ent) noexcept;

    //! Copy assignment operator.
    Entity& operator=(const Entity& ent);

    //! Move assignment operator.
    Entity& operator=(Entity&& ent) noexcept;

    //! Returns the owner of character.
    //! \return The owner of character.
    Player& GetOwner() const;

    //! Sets the owner of character.
    //! \param owner The owner of character.
    void SetOwner(Player& owner);

    //! Returns the value of game tag.
    //! \param tag The game tag of card.
    //! \return The value of game tag.
    int GetGameTag(GameTag tag) const;

    //! Sets game tag to the card.
    //! \param tag The game tag to indicate ability or condition.
    //! \param value The value to set for game tag.
    virtual void SetGameTag(GameTag tag, int value);

    //! Returns the value of cost.
    //! \return The value of cost.
    int GetCost() const;

    //! Sets the value of cost.
    //! \param cost The value of cost.
    void SetCost(int cost);

    //! Destroys character.
    virtual void Destroy();

    //! Creates entity from the card.
    //! \param player A player to get the card.
    //! \param card A card to draw.
    //! \return A pointer to entity that is allocated dynamically.
    static Entity* GetFromCard(Player& player, Card&& card);

    Card card;
    AuraEffects* auraEffects = nullptr;
    Aura* onGoingEffect = nullptr;

    std::size_t id = 0;
    std::size_t orderOfPlay = 0;

    bool isDestroyed = false;

 protected:
    Player* m_owner = nullptr;

    std::map<GameTag, int> m_gameTags;

 private:
    //! Releases dynamic allocated resources.
    void FreeMemory();
};
}  // namespace RosettaStone

#endif  // ROSETTASTONE_ENTITY_HPP
