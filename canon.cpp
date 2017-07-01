bool cannonshoot::UpdateFrame()
2 {
3 bool updateOK = theCannon.Update();
4
5 cannonball &currentBall = theCannon.CannonBall();
6 if ((currentBall.BallInFlight()) &&
7 (currentBall.Y() > theCannon.Y()+650.0f))
8 {
9 currentBall.BallHit();
10 }
11
12 return (updateOK);
13 }
14
15
16 bool cannonshoot::RenderFrame()
17 {
18 bool renderOK = theGround.Render();
19 if (renderOK)
20 {
21 renderOK = theCannon.Render();
22 }
23
24 return renderOK;
25 }
26
27
28 bool cannonshoot::OnKeyDown(
29 keyboard_input_message &theMessage)
30 {
31 vector paddleDirection;
32 float temp = 0.0f;
33
34 switch (theMessage.keyCode)
35 {
36 case KC_A:
37 temp = (float)rand();
38 while (temp > 1.0)
39 {
40 temp /= 10;
41 }
42 theCannon.ArmCannon(temp);
43 break;
44
45 case KC_F:
46 theCannon.FireCannon();
47 break;
48
49 case KC_Q:
50 GameOver(true);
51 }
52 return (false);
53 }
The UpdateFrame() function, wh
