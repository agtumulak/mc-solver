import os, string, numpy, scipy.io, sys

## Helper functions ##

def StringToArray( input_string ):
    # Read data, strip endline, split by delimiter
    text_data = input_string.rstrip().split( ',' )
    # Save to array, convert to float
    binary_data = numpy.array( text_data ).astype( numpy.float )
    # Return binary data
    return binary_data
    
def ReadName( input_string ):
    # Read name, strip endline, remove characters that will fuck with matlab
    name = input_string[1:].rstrip().replace('.','_point_')
    return name

## Main function ##

# Filename setup
csvfilename = sys.argv[1]
basename = os.path.splitext(csvfilename)[0]
matfilename = basename + '.mat'

# Tokens
scalar_start = '#mc_scalar'
angular_start = '#mc_angular'
end_token = '#end'

# Initialize dictionary
matlab_dictionary = {}

# Open file and read
with open( csvfilename, 'r') as rawdata:
    for line in rawdata:
        if line.startswith( scalar_start ):
            # Save to dictionary
            matlab_dictionary[ ReadName(line) ] = StringToArray( rawdata.next() )
        if line.startswith( angular_start ):
            # Read name, strip endline, remove invalid characters
            name = ReadName(line);
            # Read angular flux and store in array
            array = StringToArray( rawdata.next() )
            while True:
                line = rawdata.next()
                if line.startswith(end_token):
                    break
                else:
                    array = numpy.vstack( (array, StringToArray( line )) )
            matlab_dictionary[ name ] = array
            
# Save to file
scipy.io.savemat( matfilename, matlab_dictionary )
print( 'Matlab file produced! ' )
