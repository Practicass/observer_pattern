# C++ Observer Pattern Example

This is a simple implementation of the Observer Pattern in C++. The example demonstrates a feed system where users (observers) receive messages from a feed (subject).



## Usage

1. Make sure you have `g++` installed on your system.
2. Open a terminal in the project directory.
3. Run the following commands:
    ```bash
    make          # Compile the program
    ./main        # Run the compiled program
    ```

## How it works

- Users (observers) can subscribe (`attach`) to the feed system (`FeedConcreteSubject`).
- The feed system can send messages to all subscribed users (`notify`).
- Users will receive and print the messages.

## Contributing
- Miguel Aréjula Aísa
- Pablo Angusto Delgado
