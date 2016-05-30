all:
	stack build

build:
	.stack-work/install/x86_64-linux/lts-6.1/7.10.3/bin/eesite build

rebuild:
	.stack-work/install/x86_64-linux/lts-6.1/7.10.3/bin/eesite rebuild

clean:
	.stack-work/install/x86_64-linux/lts-6.1/7.10.3/bin/eesite clean

watch:
	.stack-work/install/x86_64-linux/lts-6.1/7.10.3/bin/eesite watch
