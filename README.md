# cpp-dice

This is a program that simulates a number of tosses for a number of loaded dice. Each throw is printed to the console and, at the end of all the throws, the statistics for each die is printed to the console.

## Getting Started

#### Docker

For your convenience, the environment is Docker-ized. Simply install the Docker Toolbox and then navigate to this repository's folder using the Docker shell. Execute `./docker-build` first to build the image for the first time. Once that has completed, run `./docker-run`. You should then see a shell prompt. Navigate to `/src` and you're ready to execute Make commands. After you've executed `./docker-run`, you should be able to execute `./docker-start` for subsequent runs.

You will also be able to run unit tests right out of the box with this as it downloads and extracts `googletest` automatically when building the image. The `./docker-run` command also ties the `/src` directory to the container's `/src` directory using a volume, so any changes made on your host PC will be included on the guest container as well.

#### Non-Docker

If you don't want to use Docker, you need to install `make`, `gcc`, `gcc-c++`, and `googletest` for unit tests (if you want to run them). If you want to run unit tests, you may need to edit the Makefile to point to the location of your `googletest` directory. If you do not do this, building the tests will fail.

### General

Once you're navigated to the directory on a system with `make`, `gcc`, you can execute Make commands. To run the program, execute `make main`. This will build all the needed object files and then create a `main` executable in the `output` directory. Execute `output/main example.conf` from the `/src` directory and the program should run. Follow the format in `example.conf` and you can make your own simulation scenarios.

## Learning Outcomes

This was a partial refresher for C++ as I've been working in Web-Dev for a while. I also tried to focus on Test Driven Development and used Googletest for the first time. It was a positive experience and seemed to take away a lot of the painful debugging sessions. This was the first time I used Docker to setup my development environment. There are still a lot of advanced features that I could probably leverage, but overall it was fun and surprisingly easy to use Docker. Much less painful than VMs.
