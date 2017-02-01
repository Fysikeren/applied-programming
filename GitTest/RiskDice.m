function riskDice
  redTroops = 15;
  blueTroops = 15;

  [redTroops,blueTroops] = diceRoller(redTroops,blueTroops);
end

function [attackers,defenders] = diceRoller(attackers,defenders)
  while (attackers > 0) && (defenders > 0)
    if attackers == 1
      n = 1;
    elseif attackers == 2
      n = 2;
    else
      n = 3;
    end

    if defenders == 1
      m = 1;
    else
      m = 2;
    end

    attackerdice = sort(randi(6,n,1),'descend');
    defenderdice = sort(randi(6,m,1),'descend');

    if m > n
      defendersremoved = sum(attackerdice > defenderdice(1:n));
      attackersremoved = n - defendersremoved;
    else
      defendersremoved = sum(attackerdice(1:m) > defenderdice);
      attackersremoved = m - defendersremoved;
    end

    attackers = attackers - attackersremoved;
    defenders = defenders - defendersremoved;
  end
end