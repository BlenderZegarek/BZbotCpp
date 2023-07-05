<div align="center">
    <a href="#">
        <img height="200" src="https://raw.githubusercontent.com/BlenderZegarek/BZbotCpp/main/logowbg.svg"></svg>
    </a>
</div>

</br>

<div align="center"><strong>Discord bot made in D++ library.</strong></div>

# Introduction

## Supported Platforms

Currently only Linux system is supported. Tested on Ubuntu 23.10.

## Dependencies

- cmake ()
- make ()
- g++ ()
- D++ (10.0.24 or later)
- libjsoncpp-dev (1.9.5-4 or later)
- git ()

# Setup

## Building

### Install Dependencies

Using apt:

```
$ sudo apt install cmake g++ libjsoncpp-dev git make
```

And download D++ manually from [here](https://dpp.dev/).

### Download Source Code

First, you have to download source code from GitHub.
```
$ git clone https://github.com/BlenderZegarek/BZbotCpp.git
$ cd BZbotCpp
```

Now, compile this code.
```
$ make
```

## Create config.json

```
$ ./bzbotcpp --create-config
```

After running this command, the application will create a config file, where you need to enter token and guild id.
The `config.json` should look like this.

```
{
    "token": "your token here"
    "guildId": 1234567891234567890
}
```

# Running
To run this bot enter:
```
$ ./bzbotcpp
```
