----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09.02.2021 15:46:09
-- Design Name: 
-- Module Name: PGCD - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity PGCD is
    Port ( 
        CLK : in std_logic;
        RESET : in std_logic;
        idata_a : in std_logic_vector(31 downto 0);  
        idata_b : in std_logic_vector(31 downto 0); 
        idata_en : in std_logic;
        
        odata : out std_logic_vector(31 downto 0);
        odata_en : out std_logic
    );
end PGCD;

architecture Behavioral of PGCD is
type Etat is (init , test_1, test_2, action_1, action_2, result);
signal state : Etat := init;

begin
pgcd  : process(CLK,RESET)
    begin 
    if (RESET = '1') then 
        odata <= "00000000000000000000000000000000";  
        odata_en <= '0';
    elsif(CLK'event and CLK ='1') then
        
        case state is 
        when init => 
            odata <= "00000000000000000000000000000000"; 
            odata_en <= '0';
            if(idata_en = '1') then
                state <= test_1;
            end if;
        when test_1 =>
            if(idata_a = "00000000000000000000000000000000") then 
                
            elsif( idata_b = "00000000000000000000000000000000") then 
            
       
                
    
    

end Behavioral;
