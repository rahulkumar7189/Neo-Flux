#define NOB_IMPLEMENTATION
#define NOB_STRIP_PREFIX
// #define NOB_EXPERIMENTAL_DELETE_OLD // Doesn't work on Windows
// #define NOB_WARN_DEPRECATED
#include "./thirdparty/nob.h"
#include "./src_build/configurer.c"

int main(int argc, char **argv)
{
    // NOB_GO_REBUILD_URSELF_PLUS(argc, argv, "./thirdparty/nob.h", "./src_build/configurer.c");

    const char *program = shift_args(&argc, &argv);

    const char *old_build_conf_path = "./build/build.conf";
    int build_conf_exists = file_exists(old_build_conf_path);
    if (build_conf_exists < 0) return 1;
    if (build_conf_exists) {
        // @backcomp
        nob_log(ERROR, "We found %s. That means your build folder has an old schema.", old_build_conf_path);
        nob_log(ERROR, "Instead of %s you are suppose to use %s to configure the build now.", old_build_conf_path, CONFIG_PATH);
        nob_log(ERROR, "Remove your ./build/ folder and run %s again to regenerate the folder with the new schema.", program);
        return 1;
    }

    nob_log(INFO, "--- STAGE 1 ---");

    if (!mkdir_if_not_exists("build")) return 1;

    if (argc > 0) {
        const char *command_name = shift(argv, argc);
        if (strcmp(command_name, "config") == 0) {
            // TODO: an ability to set the target through the `config` command
            while (argc > 0) {
                const char *flag_name = shift(argv, argc);
                bool found = false;
                for (size_t i = 0; !found && i < ARRAY_LEN(feature_flags); ++i) {
                    // TODO: an ability to disable flags that enabled by default
                    //   We don't have such flags yet, but maybe we will at some point?
                    if (strcmp(feature_flags[i].name, flag_name) == 0) {
                        feature_flags[i].enabled_by_default = true;
                        found = true;
                    }
                }
                if (!found) {
                    nob_log(ERROR, "Unknown command `%s`", flag_name);
                    return 1;
                }
            }
            if (!generate_default_config(CONFIG_PATH)) return 1;
            return 0;
        } else {
            nob_log(ERROR, "Unknown command `%s`", command_name);
            return 1;
        }
    }

    int config_exists = file_exists(CONFIG_PATH);
    if (config_exists < 0) return 1;
    if (config_exists == 0) {
        if (!generate_default_config(CONFIG_PATH)) return 1;
    } else {
        nob_log(INFO, "file `%s` already exists", CONFIG_PATH);
    }

    if (!generate_config_logger("build/config_logger.c")) return 1;

    Cmd cmd = {0};
    const char *stage2_binary = "build/nob_stage2";
    cmd_append(&cmd, NOB_REBUILD_URSELF(stage2_binary, "./src_build/nob_stage2.c"));
    if (!cmd_run(&cmd)) return 1;

    cmd_append(&cmd, stage2_binary);
    da_append_many(&cmd, argv, argc);
    if (!cmd_run(&cmd)) return 1;

    return 0;
}
