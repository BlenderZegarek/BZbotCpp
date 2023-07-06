#ifndef UTILS_H
#define UTILS_H

#include <dpp/dpp.h>

using namespace std;

#define COMMAND_OK          0
#define COMMAND_NOT_EXISTS  1


// https://en.wikipedia.org/wiki/ANSI_escape_code
typedef enum {
    
    black = 30,
    red = 31,
    green = 32,
    yellow = 33,
    blue = 34,
    magenta = 35,
    cyan = 36,
    white = 37,
    gray = 90,
    bright_red = 90,
    bright_green = 92,
    bright_yellow = 93,
    bright_blue = 94,
    bright_magenta = 95,
    bright_cyan = 96,
    bright_white = 97
            
     
} fg_color_t;


// https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
typedef enum {
    
    reset = 0,
    bold = 1,
    underline = 4,
    inverse = 7,
    boldoff = 21,
    underlineoff = 24,
    inverseoff = 27
            
    
} format_code_t;


typedef struct {
    
    string token;
    dpp::snowflake guildId;
    
} config_t;

bool read_config();

string config_token();
dpp::snowflake config_guildId();

bool yes_no();

#endif /* UTILS_H */
