#!/usr/bin/bash

#rsync -avzhe "ssh" ./ gpuusr@202.114.10.172:/home/gpuusr/atupal/seismicCompetition --exclude '.git' --exclude 'codegen'

rsync -avzhe "ssh" ./ sc14@10.0.4.201:/public/sc14/matlab/seismicCompetition-git --exclude '.git' --exclude 'codegen'
