#include "builtin.h"
#include "gettext.h"
#include <stdio.h>
#include "config.h"
#include "repository.h"
#include "wt-status.h"

int cmd_psuh(int argc, const char **argv, const char *prefix)
{
    int i;
    const char *cfg_name;
    struct wt_status status;

    printf(_("Pony saying hello goes here.\n"));

    printf(Q_("Your args (there is %d):\n",
              "Your args (there are %d):\n",
              argc),
           argc);
    for (i = 0; i < argc; i++)
        printf("%d: %s\n", i, argv[i]);

    printf(_("Your current working directory:\n<top-leve>%s%s\n"),
            prefix ? "/" : "", prefix ? prefix : "");

    wt_status_prepare(the_repository, &status); 
    git_config(git_default_config, &status);
    if (git_config_get_string_tmp("user.name", &cfg_name) > 0)
        printf(_("No name is found in config\n"));
    else
        printf(_("Your name: %s\n"), cfg_name);

    printf(_("Your current branch: %s\n"), status.branch);
    return 0;
}
