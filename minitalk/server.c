# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

void	send_ack(int pid)
{
	write(1, "\n", 1);
	kill(pid, SIGUSR2);
}

void	handler(int signo, siginfo_t *info, void *context)
{
	static int		ch;
	static int		check_bit;

	(void)context;
	if (check_bit < 8)
	{
		ch <<= 1;
		if (signo == SIGUSR1)
			ch |= 1;
		check_bit++;
	}
	if (check_bit >= 8)
	{
		if (ch != 0)
			write(1, &ch, 1);
		else
			send_ack(info->si_pid);
		ch = 0;
		check_bit = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;
	int					pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	s_sigaction.sa_sigaction = handler;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}