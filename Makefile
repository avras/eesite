all:
	cabal -j --sandbox-config-file=../hakyll-sandbox/cabal.sandbox.config build

build:
	dist/build/eesite/eesite build

rebuild:
	dist/build/eesite/eesite rebuild

clean:
	dist/build/eesite/eesite clean

watch:
	dist/build/eesite/eesite watch
