package com.verity.entity;

import net.minecraft.entity.EntityType;
import net.minecraft.entity.MobEntity;
import net.minecraft.entity.ai.attributes.AttributeModifierMap;
import net.minecraft.entity.ai.attributes.Attributes;
import net.minecraft.world.World;

public class EntityVerity extends MobEntity {
    
    public EntityVerity(EntityType<? extends MobEntity> type, World worldIn) {
        super(type, worldIn);
    }

    public static AttributeModifierMap.MutableAttribute setCustomAttributes() {
        return MobEntity.func_233666_p_()
                .createMutableAttribute(Attributes.MAX_HEALTH, 100.0D)
                .createMutableAttribute(Attributes.MOVEMENT_SPEED, 0.35D)
                .createMutableAttribute(Attributes.ATTACK_DAMAGE, 15.0D);
    }

    @Override
    protected void registerGoals() {
        super.registerGoals();
        // Custom AI goals will be added here
    }

    @Override
    public void tick() {
        super.tick();
        if (this.world.isRemote) {
            // Client-side particle logic
        }
    }
}
