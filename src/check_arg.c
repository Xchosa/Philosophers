











void check_arg(int argc, char **argv)
{
    void(*argv);
    if ((argc <= 4 ) || (argc >= 5))
        error_input("Error\n wrong number of arguments");


}

void error_input(*error_msg, )
{
    ft_putendl(error_msg, STDERR_INFILIO);
}