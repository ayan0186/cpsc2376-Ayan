# Board Game Cafe

## 1. Specification

Light weight program that keeps track of different board game, who's borrowing them, and when they're due back. The program also allows you to view all the games they have and how many copies there are. Additionally it should include a feature to check out a game to a customer, see what customer has what, and track when games are returned

**Entities involved**
-Board games
-Customers
-Transactions

**Functions** 
-List of all games available
-Check out a game to a customer
-Who has what game and when the game is due

## 2. Identify Nouns and Verbs

**Nouns** 
-Game (Game Name, Total copies, Availble Games)
-Customer (Name, ID)
-Due Date

**Verb**
-View all games
-Check out a game
-Return game
-List of current borrowed games

## 3. Desgining Classes

### Class: Game
**Attributes**
-string name
-int id
-int totalCopies
-int availableCopies
**Behaivor**
-Increase or decrease copies when they get checked out or returned

### Class: Customers
**Attributes**
-string name
-int id
**Behaivor**
-View the games they borrowed

### Class: Transactions
**Attributes**
-Game borrowedGame
-Cutomers borrower
-int dueDate
**Behaivor**
-Records what and how many games the customer borrowed
-Records when they returned the game

## 4. Class Diagram (Mermaid)

```mermaid
classDiagram
    class Game {
        +string name
        +int total_copies
        +int available_copies
        +bool checkout()
        +void return_game()
    }

    class Customer {
        +string name
        +int customer_id
    }

    class BorrowTransaction {
        +Game game
        +Customer customer
        +string due_date
        +bool is_overdue()
    }

    Customer "1" -- "0..*" BorrowTransaction : borrows >
    Game "1" -- "0..*" BorrowTransaction : is borrowed in >




