from cutekit import args, builder, cmds, shell


def run(_args: args.Args):
    executable = builder.build('hello-world', 'host-x86_64')
    shell.exec(executable.outfile())


cmds.append(cmds.Cmd('s', 'start', 'Run the application', run))