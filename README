This README provides instructions for running the test sets for the
SC'14 SCC MATLAB Seismic Data Analysis Scientific Application.


OVERVIEW
========

For a description of the problem, see
html/SeismicAnalysisCompetition.html.  The driver routine is
imageModelData.m.  There are also helper functions, diffStacked.p and
displayFigure.m, which are explained below in more detail.

There are two test sets: Summer Fault and Summer Salt Tooth (previously
known as fault and salt tooth).



GETTING STARTED
===============

There will be two folders: seismicCompetition and SEGY-files.  The
seismicCompetition folder contains all required MATLAB files to run
along with where the results will be stored.  At the conference, once
done, the results folder will need to be submitted.  The SEGY-files
contain the velocity model and shot record SEG-Y files.

MATHWORKS: How do teams decide which to run?

To run a model, start MATLAB and change directories to the
seismicCompetition folder.  The driver routine is imageModelData.  Type

   >> help imageModelData

for details on how to call it.  There is no installation; when
imageModelData is called, it will add the required folders to the
MATLAB path.

NOTE: It is not required that a team call imageModelData with each run
mode (serial, parallel, parallel-gpu).  These are the options to
choose from and it will be up to the teams to determine the best mode
to run.

NOTE: parallel-gpu is stubbed and not implemented.  It is not a
requirement to implement nor use a GPU.  However, if a team chooses to
use a GPU, then presumably some portion of processShotRecords.m would
be written making use of GPUs.  AGAIN: IT IS NOT REQUIRED TO WRITE A
GPU VERSION OF THE CODE, BUT IF YOU CHOOSE TO DO SO, IT WILL NEED TO
BE IMPLEMENTED.

It is strongly recommended to run at least the Summer Fault prior to
the conference and preferable the Summer Salt Tooth as well.

NOTE: The test data sets are NOT indicative of the memory requirements
for running the conference data sets.



EXAMPLE
=======

Call imageModelData as such

   imageModelData(MODEL,LOCATION-OF-SEG-Y-FILES,RUNMODE)

To run the Summer Fault test model in serial mode, call it as such:

   >> imageModelData('SummerFault','/data/SCC/SEGY-files',{'serial'})

As a reference, when tested, 100 iterations took approx. 8.5 minutes
to run serially.

To run the Summer Fault test model in parallel mode, call it as such
(10 workers is only an example and not neccessarily the recommended
pool size for this example or for any conference model).

   >> % Start a pool of 10 workers
   >> p = parpool(10);
   >> imageModelData('SummerFault','/data/SCC/SEGY-files',{'parallel'})
   >> % Close the pool
   >> p.delete

NOTE: By default parpool will open a pool of workers using the default
profile.  A local profile is shipped automatically, running the pool
of workers on the local machine.  If the pool of workers should be run
across a collection of compute nodes, a new profile will need to be
created.  The profile should instruct MATLAB to either submit to the
MATLAB job scheduler (MJS) or a 3rd party scheduler (e.g. TORQUE,
SLURM, etc.).  For more help, type

   >> docsearch 'Cluster Configuration'

to see how to either configure for MJS or configure for another
scheduler.

In the SEG-files directory, it would be expected to see the
<MODEL>ModelData folders, for instance

.
..
SummerFaultModelData	       	     	SummerSaltToothModelData

At the conference, additional ModelData folders will be added.  In
each ModelData folder will exist at least the following files

.
..
<MODEL>ShotRecords.segy	      		<MODEL>VelocityModel.segy

NOTE: When testing the SummerSaltTooth model, as a reference, 301
iterations took approx. 22 hours to run serially.



RESULTS
=======

Three result files are generated in the 'results' folder
* <MODEL>_<RunDate>.txt           : A time stamp for each iteration
* <MODEL>_<RunDate>_<RunMode>.fig : Where RunMode is defined in
                                    imageModel.m as serial, parallel,
				    or parallel-gpu.
* <MODEL>_<RunDate>_<RunMode>.mat : A stacked set of images for the
                                    serial/parallel/gpu run 

If the run is complete, the scoring will be based on the
<MODEL>_<RunDate>_<RunMode>.mat, by using the diffStacked routine to
compare to the baseline.  If the run is not complete, the timings file
will be viewed to see how much was completed in what period of time.

To compare a run with a sample run, run diffStacked

>> diffStacked(MODEL,RUN-1,RUN-2)

Such that one of the runs is the benchmark.  It doesn't matter which
run is listed first.  In theory, the parallel and serial run should
return the same results, so comparing the two files yields the
following:

>> score = diffStacked('SummerFault','results/SummerFault_SampleRun_serial','results/SummerFault_SampleRun_parallel')
score =
   100

The score tells, to a certain tolerance, the absolute difference
between the two images.  100 is the best score, 0 is the worst.  To
compare the run with yours, replace one of the files with your result
file.  For instance:

>> score = diffStacked('SummerFault','results/SummerFault_SampleRun_serial','results/SummerFault_01-Jan-2014_01-01-01_parallel');

Again, it doesn't matter which file a test result is compared against
to (serial or parallel) nor does it matter the order you list them
when calling diffStacked.

To redisplay a run, call displayFigure
>> displayFigure('results/SummerFault_SampleRun_serial')


For comparisons, the Fault and Salt Tooth models were solved in serial
mode and parallel mode.  The resulting stacked images (.mat) and
figures (.fig) have been placed in the results folder.



#
