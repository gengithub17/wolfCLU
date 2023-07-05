#include <wolfclu/clu_header_main.h>
#include <wolfclu/clu_log.h>
#include <wolfclu/clu_optargs.h>
#include <wolfclu/server.h>

#ifndef WOLFCLU_NO_FILESYSTEM

static const struct option server_options[] = {
    {"-port",           required_argument, 0, WOLFCLU_PORT                  },
    {"-key" ,           required_argument, 0, WOLFCLU_KEYFILE               },
    {"-cert",           required_argument, 0, WOLFCLU_CERTFILE              },
    {"-help",           no_argument,       0, WOLFCLU_HELP                  },
    {"-h",              no_argument,       0, WOLFCLU_HELP                  },
    {0,0,0,0}
};

static void wolfCLU_ServerHelp(void) 
{
    WOLFCLU_LOG(WOLFCLU_L0, "./wolfssl s_server");
    WOLFCLU_LOG(WOLFCLU_L0, "\t-port <+int>");
    WOLFCLU_LOG(WOLFCLU_L0, "\t-key <private key file name>");
    WOLFCLU_LOG(WOLFCLU_L0, "\t-cert <cert file name>");
}

#define MAX_SERVER_ARGS 7

#endif /* !WOLFCLU_NO_FILESYSTEM */

int wolfCLU_Server(int argc, char** argv)
{
    int ret = WOLFCLU_SUCCESS;
    int longIndex = 1;
    int option;

    word16 port = wolfSSLPort;
    char* ourKey = NULL;
    char* ourCert = NULL;

    opterr = 0;
    optind = 0;

    while ((option = wolfCLU_GetOpt(argc, argv, "", server_options, &longIndex))
                    != -1) {
        
        switch (option) {
            case WOLFCLU_PORT:
                port = (word16)atoi(optarg);
                break;
            case WOLFCLU_KEYFILE:
                ourKey = optarg;
                break;
            case WOLFCLU_CERTFILE:
                ourCert = optarg;
                break;
            case WOLFCLU_HELP:
                wolfCLU_ServerHelp();
                return WOLFCLU_SUCCESS;
        }
    }

    server_test(port, ourKey, ourCert);
    
    return ret;
}

