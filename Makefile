all:
	stack build

build:
	stack exec site build

rebuild:
	stack exec site rebuild

clean:
	stack exec site clean

watch:
	stack exec site watch

sync:
	rsync -r -a -v -e ssh --delete ~/my/docs/eesite/_site/ sarva@10.107.1.1:/home/faculty/sarva/public_html/
