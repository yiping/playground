function [xStar, idxB] = oneStepSimplex(c, b, A, idxB)

    B = A(:,idxB);
    idxN = ~idxB;
    N = A(:,idxN);
    
    n = length(c);
    cB = c(idxB);
    cN = c(idxN);
    
    nb = size(B,1);

    if nb ~= size(B',1)
        error('B has to be square'); 
    end
    xB = B \ b;
    xN = zeros(n - nb,1);
    
    % mulitplier for equality constraint, assuming sB = zero vec
    pi = B' \ cB;
    sN = cN - N'*pi; % pricing step
    
    if sN >= 0
        % satisfied KKT condition, exit
        xStar = [xB; xN];
        return;
    end
    
    % if sN not non-negative, pick the most negative sq such that sq<0
    % dir is an update direction
    [~, idq ] = min(sN);
    Aq = N(:,idq);
    dir = B \ Aq;
    
    % xB_new = xB - inv(B)*Aq*xq
    % c'*x_new = cB'*xB - cB'*[inv(B)*Aq]*xq_new + cq*xq_new;
    % As
    % cB'*inv(B) = pi'
    % and
    % Aq'*pi = cq -sq
    % we have
    % cB'*[inv(B)*Aq]*nq_new = pi'*Aq*xq_new = (cq - sq)*xq_new
    % FINALLY
    % c'*x_new = cB'*xB - sq*xq_new
    if dir <= 0
        % problem is unbounded
        error('linear problem is unbounded.')
    end
    
    % compute xq_new
    stepLen = xB./dir;
    [~, idp] = min(stepLen);
    xq_new = stepLen(idp);
    
    xB_new = xB - dir*xq_new;
    % double check: xB(idp) should be zero now
    if abs(xB(idp)) > 1e-9
        error('xB error') 
    end    
    
    % update idxB, removing idp and adding idq
    tmp = 1:length(idxB);
    cntB = tmp(idxB == 1);
    iB_toRemove = cntB(idp);

    tmp = 1:length(idxN);
    cntN = tmp(idxN == 1);
    iB_toAdd = cntN(idq);
    
    idxB(iB_toRemove) = 0;
    idxB(iB_toAdd) = 1;

end