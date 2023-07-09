#include <dpp/dpp.h>

//#include <Magick++.h>

#include "pfp.h"

using namespace std;
//using namespace Magick;

bool _pfp(const dpp::slashcommand_t& event, int &exit_code, colors_t colors) {
    
    if (!(event.command.get_command_name() == "pfp")) return false;
    
    dpp::command_interaction cmd_data = event.command.get_command_interaction();
    
    auto usr = event.command.usr;
    
    dpp::user user = event.command.get_resolved_user(
        cmd_data.get_value<dpp::snowflake>(0)
    );

    dpp::embed embed = dpp::embed().
        set_color(0x9B00EC).
        set_title("PFP").
        set_description( user.username + "'s avatar:" ).
        set_image( user.get_avatar_url(1024) ).
        set_footer(dpp::embed_footer().set_text( (usr.discriminator == 0) ? usr.username : usr.format_username() ).set_icon(usr.get_avatar_url()) ).
        set_timestamp(time(0));
                
    event.reply(dpp::message(event.command.channel_id, embed));
    
    exit_code = COMMAND_OK;
    
    return true;
    
}      

void _register_pfp(dpp::cluster& bot) {
    
    dpp::slashcommand pfp("pfp", "Gets avatar of provided person.", bot.me.id);
    pfp.add_option(
        dpp::command_option(dpp::co_user, "user", "The user whose avatar you want to see.", true)
    );

    bot.guild_command_create(pfp, config_guildId());
    
}
