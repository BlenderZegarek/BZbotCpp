#include <dpp/dpp.h>
#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>
#include "Magick++.h"

#include "utils.h"

using namespace std;

config_t bot_config;

string config_token() {
    return bot_config.token;
}

dpp::snowflake config_guildId() {
    return bot_config.guildId;
}

colors_t* config_colors() {
    return &bot_config.colors;
}

uint32_t config_get_color(string name) {
    for (int i = 0; i < bot_config.num_colors; i++) {
        if (name == bot_config.colors[i].color_name) {
            return bot_config.colors[i].color_value;
        }
    }
    return 0;
}

bool read_config() {
    
    ifstream config_file("config.json");
    Json::Reader config_reader;
    Json::Value config;
    if (!config_reader.parse(config_file, config))
        return false;
    
    if (config["token"].empty() || config["guildId"].empty())
        return false;
    
    bot_config.token = config["token"].asString();
    bot_config.guildId = config["guildId"].asUInt64();
    bot_config.num_colors=0;
 
    for (auto it = config["colors"].begin(); it != config["colors"].end(); it++) {

        bot_config.colors[bot_config.num_colors].color_name = it.key().asString();
        bot_config.colors[bot_config.num_colors].color_value = config["colors"][it.key().asString()].asInt();

        bot_config.num_colors++;
        
    }
    
    return true;

}

bool yes_no() {
    int key;

    do {

        key = getchar();

    } while ((key != 121) && (key != 110));

    if (key == 121) {

        return true;

    }

    return false;
}