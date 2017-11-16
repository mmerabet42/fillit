#!/usr/bin/perl
use warnings;
use strict;
die "enter n and density" unless (scalar(@ARGV) == 2);
my ($x, $density) = @ARGV;

for (my $k = 0; $k < $x; $k++) {
	for (my $i = 0; $i < 4; $i++) {
		for (my $j = 0; $j < 4; $j++) {
			if (int(rand(4) * 2) < $density) {
				print "#";
			}
			else {
				print ".";
			}
		}
				print "\n";
	}
			print "\n";

}
