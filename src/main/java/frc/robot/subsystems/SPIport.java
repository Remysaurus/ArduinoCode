package frc.robot.subsystems;


import java.nio.ByteBuffer;
import edu.wpi.first.wpilibj.SPI;
import edu.wpi.first.wpilibj.SPI.Mode;
import edu.wpi.first.wpilibj.SPI.Port;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj2.command.SubsystemBase;



public class SPIport extends SubsystemBase {

  public static final class ArduinoCommand {
    public static final double kGreen = 1;
    }

  
  private ByteBuffer m_byteBuffer = ByteBuffer.allocate(8);
  private SPI m_port = new SPI(Port.kOnboardCS0);

  private double m_receiveDouble;
  
  public SPIport() {
    m_port.setClockRate(9600);
    m_port.setMode(Mode.kMode0); //clock idle low, data sampled on rising edge


};

  public double write(double write) {
    
    m_byteBuffer.putDouble(0, write);
    m_port.write(m_byteBuffer, 8);
    m_receiveDouble = m_byteBuffer.getDouble(0);
    SmartDashboard.putNumber("e", m_receiveDouble);
    return m_receiveDouble;
    
    
  }

  @Override
  public void periodic() {
    
  }
}
