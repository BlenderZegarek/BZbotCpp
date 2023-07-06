#include <dpp/dpp.h>

#include "utils.h"

#include "pfp.h"

using namespace std;

bool _pfp(const dpp::slashcommand_t& event, int &exit_code) {
    
    if (!(event.command.get_command_name() == "pfp")) return false;
    
    dpp::command_interaction cmd_data = event.command.get_command_interaction();
    
    dpp::user user = event.command.get_resolved_user(
        cmd_data.get_value<dpp::snowflake>(0)
    );

    dpp::embed embed = dpp::embed().
        set_color(0xff00d8).
        set_title("PFP").
        set_description( user.username + "'s avatar:" ).
        set_image( user.get_avatar_url(1024) ).
        set_footer(dpp::embed_footer().set_text(event.command.usr.format_username()).set_icon(event.command.usr.get_avatar_url())).
        set_timestamp(time(0));
                
    event.reply(dpp::message(event.command.channel_id, embed));
    
    exit_code = COMMAND_OK;
    
    return true;
    
}      

void _register_pfp(dpp::cluster& bot) {
    
    dpp::slashcommand pfp("pfp", "Gets avatar of provided person.", bot.me.id);
    pfp.add_option(
        dpp::command_option(dpp::co_user, "user", "asd", true)
    );

    bot.guild_command_create(pfp, config_guildId());
    
}
