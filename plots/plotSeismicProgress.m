function plotSeismicProgress(units,x,z,v,t,shot,M,Stacked,ixs,vwin,elaptime)

only_baseline_flag = nargin==4;

xl = sprintf('Distance (%s)',units{1});
zl = sprintf('Depth (%s)',units{1});
tl = sprintf('Time (%s)',units{2});

if only_baseline_flag==false
    subplot(4,1,1)
end
imagesc(x,z,v)
xlabel(xl), ylabel(zl)
title('Velocity Model')
ax = axis;
%axis equal tight

if only_baseline_flag==false
    % draw shot window
    hold on
    %plot(x(vwin(1)),z(1),'w*');
    xwin = [x(vwin(1)), x(vwin(2)), x(vwin(2)), x(vwin(1)), x(vwin(1))];
    zwin = [z(1), z(1), z(end), z(end), z(1)];
    plot(xwin,zwin,'w-');
    hold off
end

% Modify colormap to show ocean
cmap = colormap(seismic);
cmap(1,:) = [0 0 0];
colormap(cmap)

if only_baseline_flag==false
    % assume all plots exist now
    subplot(4,1,2)
    Stacked = colorScaling(Stacked);
    imagesc(x,z,Stacked)%diff(Stacked,2,1))
    xlabel(xl); ylabel(zl);
    title(['Stacked Image: Elapsed time ',hms(elaptime)]);
    %axis equal tight
    
    %caxis([-1 1])
    
    subplot(4,1,3)
    imagesc(xwin(1:2),[1,t],shot')
    xlabel(xl); ylabel(tl);
    title(['Current Shot ',num2str(ixs)]);
    caxis([-0.1 0.1])
    axis([ax(1:2), [1,t]])
    
    subplot(4,1,4)
    M = colorScaling(M);
    imagesc(xwin(1:2),[1,t],M)
    xlabel(xl); ylabel(tl);
    title(['Current Migrated Shot ',num2str(ixs)]);
    %caxis([-0.1 0.1])
    axis([ax(1:2), [1,t]])
end

drawnow

end % plotSeisimicProgress

function cs = colorScaling(signal)

sig = mean(signal,2);
[upperenv, lowerenv] = envelope(sig);
upperenv = envelope(upperenv);
[~, lowerenv] = envelope(lowerenv);

[al,bl] = fitexp(lowerenv);
[au,bu] = fitexp(upperenv);
eqexp = @(x,a,b) a*exp(b*x);

x = 1:length(sig);

cs(:,1) = eqexp(x,-al,bl);
cs(:,2) = eqexp(x,au,bu);
%{
plot(sig,'r')
hold on
plot(upperenv,'.')
plot(lowerenv,'.')
plot(cs(:,1),'ko')
plot(cs(:,2),'ko')
hold off
%}

csmean = repmat(mean(cs,2),1,size(signal,2));
csrange= repmat(diff(cs,1,2),1,size(signal,2));

cs = signal-csmean;
cs = cs./csrange;
end % colorScaling

function [a,b] = fitexp(signal)
signal = abs(signal);
x = 1:length(signal);
lny = log(signal);
A = [ones(length(x),1) x'];
b = lny';
coeff = A\b;
a = exp(coeff(1));
b = coeff(2);
end % fitexp
