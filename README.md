# Simple Store Management System

## Overview
This project is a **Simple Store Management System** written in C. It allows users to:
- View available products
- Place orders
- Cancel orders
- Review products

## Developers
This project was developed by:
- Sadi
- Sahidul
- Abed
- Mubasshir

**Project Documentation** was written by Mubasshir.

## Features
- **Product Management:** Displays available items along with quantity and price.
- **Order System:** Users can place orders by selecting product codes and quantities.
- **Order Cancellation:** Users can cancel their order using their phone number.
- **Product Review:** Customers can rate products, and only the highest rating is stored.

## File Structure
- `product.txt` - Stores product details (ID, Name, Quantity, Price).
                  Here is an example of an item : 1 Dates 43 790.00. here "1" is product id,
                  "Dates" is item name, "43" is quantity, "790.00" is the price of per amount.
                  when user select view items, the code shows all item, the code extract information
                  from product.txt
- `order.txt` - Stores customer orders (Address, Contact Number, Total Price).
- `review.txt` - Stores product reviews (Product ID, Max Rating).
- `temp.txt` - A temporary file is used during order cancellation and review updates.
              The contact which is not equal to the cancelled order that is saved in temp.txt.
              After that temp.txt is renamed as order.txt for future operation.
## How to Use
1. **Compile the Program:**
   ```bash
   gcc store_management.c -o store_management
   ```
2. **Run the Program:**
   ```bash
   ./store_management
   ```
3. **Follow the On-Screen Instructions** to interact with the system.

## Example Input/Output
### Viewing Products:
```
Total Item: 3
Code    Name        Quantity    Price(per Kg)
1       Rice        50          60.00
2       Sugar       30          120.00
3       Oil         20          200.00
```

### Placing an Order:
```
Product code - 1
Quantity - 5
Total Price = 300.00
Your order is successful.
```

### Canceling an Order:
```
Enter phone number: 1234567890
Order canceled successfully.
```

## Future Improvements
- Implement a graphical user interface (GUI).
- Add user authentication for better security.
- Improve data storage using a database instead of text files.


---


