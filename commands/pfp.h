#ifndef PFP_H
#define PFP_H

#include "../utils/utils.h"

bool _pfp(const dpp::slashcommand_t& event, int &exit_code, colors_t colors);

void _register_pfp(dpp::cluster& bot);

#endif /* PFP_H */

