// SPDX-License-Identifier: GPL-2.0
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

#ifdef CONFIG_KSU_SUSFS_SPOOF_PROC_CMDLINE
extern int susfs_spoof_proc_cmdline(struct seq_file *m);
#endif

static int cmdline_proc_show(struct seq_file *m, void *v)
{
#ifdef CONFIG_KSU_SUSFS_SPOOF_PROC_CMDLINE
	if (!susfs_spoof_proc_cmdline(m)) {
		seq_putc(m, '\n');
		return 0;
	}
#endif
	seq_printf(m, "%s\n", saved_command_line);
	return 0;
}
