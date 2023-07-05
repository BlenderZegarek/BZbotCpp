#include <dpp/dpp.h>
#include <jsoncpp/json/json.h>
#include <iostream>
#include <fstream>

#include "utils.h"

using namespace std;

config_t bot_config;

string config_token() {
    return bot_config.token;
}

dpp::snowflake config_guildId() {
    return bot_config.guildId;
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