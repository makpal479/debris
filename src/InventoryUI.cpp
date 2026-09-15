#include "InventoryUI.h"

InventoryUI::InventoryUI()
{
    slotTexture.loadFromFile("assets/slot.png");
    woodTexture.loadFromFile("assets/woodSlot.png");
}

void InventoryUI::draw(
    sf::RenderWindow& window,
    const Inventory& inventory)
{
    sf::View oldView = window.getView();
    window.setView(window.getDefaultView());

    sf::Sprite slot;
    slot.setTexture(slotTexture);

    const float slotSize = 48.f;
    const int slotCount = 10;

    const float totalWidth = slotSize * slotCount;

    sf::Vector2f viewSize =
        window.getDefaultView().getSize();

    const float startX =
        (viewSize.x - totalWidth) / 2.f;

    const float y =
        viewSize.y - slotSize - 20.f;

    for (int i = 0; i < slotCount; ++i)
    {
        slot.setPosition(
            startX + i * slotSize,
            y);

        window.draw(slot);
    }
    if (inventory.getItemCount(ItemType::Wood) > 0)
{
    sf::Sprite wood;
    wood.setTexture(woodTexture);

    wood.setPosition(
        startX,
        y
    );

    window.draw(wood);
}

    window.setView(oldView);
}