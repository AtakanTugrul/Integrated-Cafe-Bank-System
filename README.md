# Integrated-Cafe-Bank-System
This is my most complex project so far. It connects two different C programs using a text file as a database.

## How does it work?
There are two programs talking to each other:
1.  **Bank (ATM)**: You can deposit or withdraw money here. It saves your balance to a file called `bakiye.txt`.
2.  **Cafe:** You can order food or coffee here. If you pay with a Credit Card, it reads the `bakiye.txt` file and cuts the price from your bank account.

## Steps to Run
Please follow this order, otherwise it might not find the file:
1.  Run **`Kart.c`** first and add some money.
2.  Then run **`Cafe.c`** and order something.
3.  Choose "Credit Card" to see how the balance updates automatically.

## What I learned?
* **File I/O:** Reading and writing to `.txt` files in C.
* **System Design:** How to make two programs share data.
