#!/usr/bin/bash

rsync -avzhe "ssh" ./ gpuusr@202.114.10.172:/home/gpuusr/atupal/seismicCompetition --exclude '.git' --exclude 'codegen'
