# polymorphism_in_cpp
Use of a simple class hierarchy as the basis for a fantasy combat game.

RULES

- \*Glare- If a Medusa rolls a 12 in attack then the target has looked her in the eyes and is turned to stone. The Medusa wins!
  - Medusa can be turned to stone by another Medusa
- \*Ring- Gollum as the one ring. It can make him invisible. That is essentially his defense!
  - It also allows him to occasionally get behind his opponent and jump on their back. There is a 5% chance he makes an attack with 3d6.
  - Gollum will attack with 1d6, unless, it is the 1 in 20 (i.e. 5%) chance that he attacks with 3d6.  In that case you don&#39;t roll the 1d6.
- \*Mob- The Blue Men are actually a swarm of (3) small individuals. For every 4 points of damage (round down) they lose one defense die.
  - When they reach strength of 8 they have 2d6 for defense.
  - When he reaches strength of 4&lt;= he has 1d6 for defense.
- \*Hogwarts- If Harry dies (i.e. strength &lt;=0) he immediately recovers. His strength becomes 10 again, for a max of 20 for the fight. If he were to die again then he&#39;s dead.
  - After the first attack where his strength is less than 0, it is reset to 10.

NOTES

- 3d6 is rolling three 6-sided dice. 2d10 is rolling two 10-sided dice.
- Main() will check character strength and terminate or continue combat based on those values.
- To resolve an attack, generate 2 dice rolls.
  - FIRST ROLL
    - The attacker rolls the appropriate number and type of dice under _Attack_.
    - That amount of damage is passed to the defender in the defender object&#39;s defense function.
  - SECOND ROLL
    - The defender rolls the appropriate number and type of dice under _Defense_.
    - Subtract the Defense roll from the Attack roll. That is the _damage_.
    - Defense rolls that are &gt;= _damage_ simply thwart the attack
- To apply _damage_, subtract the Armor value from _damage_ value.
  - The result is then subtracted from the Strength Points.
  - That value becomes the new Strength Points for the next round.
  - If Strength Points goes to 0 or less, then the character is out of combat.
-  _attack_ and _defense_ function interaction.
  - Something like this:
    - hits = Creature1.attack();
    - defense(hits);
- The parent class is an **abstract class**.
  - Since each starts with the same data elements, there is only one constructor. 
  - Consider attack() and defense()
    - Incorporated into the class hierarchy.

- To manage combat, create two pointers to Creature, say fighter1 and fighter2.
  - You will instantiate each to the appropriate derived class object.
- main() function is limited to calling the _attack_ and _defend_ functions.
  - All other actions should be enclosed in each derived class.


BY DESIGN…

- Medusa&#39;s &quot;Glare&quot; is designed to &quot;kill&quot; her opponent, so I&#39;m going to interpret that as her attacking with a very large hit or attack number.
- In order to define a &quot;5% chance&quot; to trigger Gollum&#39;s special case, I&#39;m going to use the generation of two random numbers between 0-19 such that when the two numbers are the same, Gollum attacks with 3d6.
