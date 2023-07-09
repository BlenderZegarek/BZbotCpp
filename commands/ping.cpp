#include "ping.h"
#include "utils.h"

bool _ping(const dpp::slashcommand_t& event, int &exit_code, colors_t colors) {
    
    if (!(event.command.get_command_name() == "ping")) return false;
    
    auto usr = event.command.usr;
                      
    dpp::embed embed = dpp::embed().
        set_color( config_get_color("default") ).
        set_title("Pong!").
        set_footer(dpp::embed_footer().set_text( (usr.discriminator == 0) ? usr.username : usr.format_username() ).set_icon(usr.get_avatar_url()) ).
        set_timestamp(time(0));

    event.reply(dpp::message(event.command.channel_id, embed));
    
    exit_code = COMMAND_OK;
    
    return true;

}

void _register_ping(dpp::cluster& bot) {
    
    dpp::slashcommand ping("ping", "Replies with pong.", bot.me.id);

    bot.guild_command_create(ping, config_guildId());

}