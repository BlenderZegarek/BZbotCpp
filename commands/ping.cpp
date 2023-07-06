#include "ping.h"
#include "utils.h"

bool _ping(const dpp::slashcommand_t& event, int &exit_code) {
    
    if (!(event.command.get_command_name() == "ping")) {
        return false;
    }
                      
    dpp::embed embed = dpp::embed().
        set_color(0xff00d8).
        set_title("Pong!").
        set_footer(dpp::embed_footer().set_text(event.command.usr.format_username()).set_icon(event.command.usr.get_avatar_url())).
        set_timestamp(time(0));

    event.reply(dpp::message(event.command.channel_id, embed));
    
    exit_code = COMMAND_OK;
    
    return true;

}

void _register_ping(dpp::cluster& bot) {
    
    dpp::slashcommand ping("ping", "Replies with pong.", bot.me.id);

    bot.guild_command_create(ping, config_guildId());

}