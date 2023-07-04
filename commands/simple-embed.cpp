#include <dpp/dpp.h>

#include "utils.h"

// #include "ping.h"
#include "simple-embed.h"

using namespace std;

bool _simple_embed(const dpp::slashcommand_t& event, int &exit_code) {
    
    if (!(event.command.get_command_name() == "simple-embed")) return false;
    
    dpp::command_interaction cmd_data = event.command.get_command_interaction();
    
//    dpp::embed embed = dpp::embed().
//        set_color(0xff0000).
//        set_title( cmd_data.get_value<string>(0) ).
//        set_description( cmd_data.get_value<string>(2) ).
//        set_footer(dpp::embed_footer().set_text(event.command.usr.format_username()).set_icon(event.command.usr.get_avatar_url())).
//        set_timestamp(time(0));

    dpp::embed embed = dpp::embed().
        set_color( stoi(cmd_data.get_value<string>(1)) ).
        set_title( cmd_data.get_value<string>(0) ).
        set_description( cmd_data.get_value<string>(2) ).
        set_footer(dpp::embed_footer().set_text(event.command.usr.format_username()).set_icon(event.command.usr.get_avatar_url())).
        set_timestamp(time(0));
                
    event.reply(dpp::message(event.command.channel_id, embed));
    
    //event.reply("dziala");
    exit_code = COMMAND_OK;
    
    return true;
    
}      

void _register_simple_embed(dpp::cluster& bot) {
    
    dpp::slashcommand simple_embed("simple-embed", "Creates simple embed.", bot.me.id);
    simple_embed.add_option(
        dpp::command_option(dpp::co_string, "title", "Embeds title.", true)
    );
    simple_embed.add_option(
        dpp::command_option(dpp::co_string, "hexcolor", "Embeds color", true)
    );
    simple_embed.add_option(
        dpp::command_option(dpp::co_string, "description", "Embeds description.", false)
    );

    bot.guild_command_create(simple_embed, config_guildId());
    
}
