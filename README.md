# Movie Ticket Booking System :film_projector:

## Description:
A CLI movie ticket booking system created using C++. The main purpose of this project was to implement basic Object Oriented Programming concepts like abstraction, inheritance and encapsulation.
The program also implements file handling and for each succesful booking, the file is appended with the unique user_id generated through the built in random() in C++. It also uses
basic input formatting although the input is not stored in a databse but rather is printed on the file. There is also a function to generate seat map for each hall which can be commented
out at first so that three identical files are created for each hall. 

## Algorithm:
```
Step 1. function menu(list, timing, seat)
    Step 1.1 select movie
    Step 1.2 select timing
    Step 1.3. select seat
Step 2. function customerInfo (name, mobile no., email)
    Step 2.1 enter customer name 
    Step 2.2 enter customer mobile no.
        Step 2.2.1 enter 10 digit no.
        Step 2.2.2 if incorrect then reenter
    step 2.3 enter customer email id
        Step 2.3.1 enter valid email id
        Step 2.3.2 if invalid then reenter
Step 3. function payment( customer details, payment type)
    Step 3.1 display customer details
        Step 3.1.1 display customer name 
        Step 3.1.2 display customer mobile no.
        Step 3.1.3 display customer email id
    Step 3.2 if details = correct ->confirm, else -> reenter
    Step 3.3 payment type
        Step 3.3.1 enter UPI ID
        Step 3.3.2 if find = @ -> return 1, else ->0
Step 4. int main()
    step 4.1 call menu()
    step 4.2 call customerinfo()
    step 4.3 call payment()
        step 4.3.1 if return 1 -> display payment done
        step 4.3.2 else return 0 -> redirect to payment()
STOP
```

