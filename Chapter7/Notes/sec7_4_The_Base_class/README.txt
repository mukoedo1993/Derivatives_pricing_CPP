ExoticEngine::DoOnePath(const MJArray& 
                            SpotValues)const
                            
DoOnePath is only slightly more complicated. The array of spot values is passed into the product to get cash-flows. 
These cash-flows are then looped over and discounted appropriately. The discounting is simplified by using the precomputed
discount factors.

We have now set up the structure for pricing path-dependent exotic derivatives but we still have to actually define the classes which
will do the path generation and define the products.
