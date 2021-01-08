Q: Rewrite the classes here so that they pass the logs of spot values around instead of the spot values. Show that the discrete barrier option and the geometric
Asian need fewer exponentiations.

A: I just did the geometric Asian Options part for this question. It is a necessity to pass the logs of spot values. Otherwise, the multiplication of sequences will
be too large for a single double or long double to hold.
