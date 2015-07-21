all:
	stack build

build:
	.stack-work/install/x86_64-linux/lts-2.19/7.8.4/bin/eesite build

rebuild:
	.stack-work/install/x86_64-linux/lts-2.19/7.8.4/bin/eesite rebuild

clean:
	.stack-work/install/x86_64-linux/lts-2.19/7.8.4/bin/eesite clean

watch:
	.stack-work/install/x86_64-linux/lts-2.19/7.8.4/bin/eesite watch
