# Inventory Management System

## Overview
This is a basic inventory management system written in C. It allows users to add, update, view, and delete items from the inventory.

## Features
- Add items with name, quantity, and price
- Update the quantity of an existing item
- Display all inventory items in a table format
- Delete items from the inventory
- Simple, user-friendly menu

## How to Use
1. Run the program.
2. Choose an option from the menu:
   - **1**: Add items
   - **2**: Update quantity
   - **3**: Display inventory
   - **4**: Delete item
   - **5**: Exit
3. Follow the prompts to enter item details.
4. Continue managing inventory or exit the program.

## Code Structure
- `struct Item`: Holds item details.
- `displayInventory()`: Displays all items in a table format.
- `deleteItem()`: Removes an item from the inventory.
- `main()`: Handles user interaction.

## Requirements
- C compiler (e.g., GCC)
- Standard C libraries (`stdio.h`, `string.h`)

## Future Improvements
- Add file storage to persist inventory data.
- Implement a search function for quick lookup.
- Enhance input validation for better usability.

---

This simple inventory system is great for basic stock management!
