#include <dpp/dpp.h>
#include <filesystem>

#include "ping.h"
#include "simple-embed.h"

#include "utils.h"

template <typename T>

void print_colored(T text, fg_color_t color_code, format_code_t format_code, bool endl, bool time_stamp) {
    
    // https://en.cppreference.com/w/cpp/chrono/c/strftime
    
    std::time_t t = std::time(nullptr);

    char mbstr[100];

    if (time_stamp)
    
        if (std::strftime(mbstr, sizeof(mbstr), "%T", std::localtime(&t)))
            std::cout << "[" << mbstr << "] ";
    
    std::cout << "\033[" << format_code << ";" << color_code << "m" << text << "\033[0m";
    if (endl) std::cout << std::endl;
}

using namespace std;

int main(int argc, char* argv[]) {
    
    if (argc > 1) {
        
        string _arg = argv[1];
        
        if ((argc == 2) && (_arg == "--create-config")) {
            
            bool need_create = false;
            
            if (!filesystem::exists("config.json"))
            {
                print_colored("\"config.json\" file does not exist, create it? [y/n]", blue, reset, true, true);
                need_create = yes_no();

            } else {
                print_colored("\"config.json\" exists, create a new one? [y/n]", blue, reset, true, true);
                need_create = yes_no();
            }
            
            if (need_create) {

                ofstream cfile;
                
                cfile.open("config.json", ofstream::out);

                cfile << "{" << endl << "    \"token\" : \"your token here\"," << endl << "    \"guildId\" : 1234567891234567890" << endl << "}" << endl;

                cfile.close();
                
                print_colored("Created the \"config.json\" file, replace the token and guild id in it", green, reset, true, true);
                
            }

        } else {
            
            print_colored("Wrong parameters.", red, reset, true, true);
            
            return 1;
            
        }
        
        return 0;
        
    }
    
    if (!read_config()) {
        print_colored("The config file does not exist or is invalid.", red, reset, true, true);
        print_colored("Read README.md.", red, reset, true, true);
        return -1;
    }

    dpp::cluster bot(config_token());

    // bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([](const dpp::slashcommand_t& event) {

        int exit_code = COMMAND_OK;

        if (!(_ping(event, exit_code)))
        if (!(_simple_embed(event, exit_code)))
        {

            dpp::embed embed = dpp::embed().
                set_color(0xdc3545).
                set_title("Komenda nieobsługiwana.").
                set_description("Wywołana komenda \"**" + event.command.get_command_name() + "**\" nie jest obsługiwana.").
                set_footer(dpp::embed_footer().set_text(event.command.usr.format_username()).set_icon(event.command.usr.get_avatar_url())).
                set_timestamp(time(0));

            //event.reply(string("kod błędu: ")+to_string(exit_code));
            event.reply(dpp::message(event.command.channel_id, embed));

            print_colored("User tried to run not supported command '", red, reset, false, true);
            print_colored(event.command.get_command_name(), blue, bold, false, false);
            print_colored("' (", red, reset, false, false);
            print_colored(event.command.usr.format_username(), blue, bold, false, false);
            print_colored(")", red, reset, true, false);


        }



    });

    bot.on_ready([&bot](const dpp::ready_t& event) {

        print_colored("Logged in as ", green, reset, false, true);
        print_colored(bot.me.format_username(), blue, bold, false, false);
        print_colored(".", green, reset, true, false);

        // bot.global_command_delete_sync(1124780043135111290);
        if (dpp::run_once<struct register_bot_commands>()) {
            _register_ping(bot);
            _register_simple_embed(bot);   
        }
    });

    bot.start(dpp::st_wait);
    
}

