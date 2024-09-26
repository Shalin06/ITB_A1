simple Seed
{
    gates:
        inout g[];
}

simple Peer
{
	gates:
	    inout g[];
}

network Network {
 	parameters:
 	    int number_of_seeds = default(3);
 		int number_of_peers = default(3);
 	submodules:
 	    seeds[number_of_seeds]: Seed {
 	    	parameters: 
 	    	    @display("p=122,178,m,4,80,80;");
 	    }  
 	    
 	    peers[number_of_peers]: Peer {
 	    	parameters: 
 	    	    @display("p=572,178,m,3,80,80;");	
 	    }
}