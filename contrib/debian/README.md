
Debian
====================
This directory contains files used to package dstrad/dstra-qt
for Debian-based Linux systems. If you compile dstrad/dstra-qt yourself, there are some useful files here.

## dstra: URI support ##


dstra-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install dstra-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your dstraqt binary to `/usr/bin`
and the `../../share/pixmaps/dstra128.png` to `/usr/share/pixmaps`

dstra-qt.protocol (KDE)

